#!/bin/bash

# This script is meant to automate the rotation of DKIM signing keys every month
# Please choose a time like 3 - 4 am SGT (note: server time is different) to do the change so as to minimize chances of a mail being sent while the keys are being changed
# Script must be run as root
# The backups is the month the backup was made

# made to follow tutorial https://linode.com/docs/email/postfix/configure-spf-and-dkim-in-postfix-on-debian-8/#configure-opendkim

DATE=`date '+%Y%m'`
# DATE="201804"
DIR="/home/sunyudong/dkim/$DATE"
# DIR="./"
ZONE="<redacted>"
AuthEmail="<redacted>"
AuthKey="<redacted>"


if [ ! -d "$DIR" ]; then
  mkdir -p "$DIR"
fi

cd "$DIR"

# Create the new keys
	opendkim-genkey -b 4096 -h rsa-sha256 -r -s $DATE -d theenglishtuitioncorner.com -v > opendkim-genkey.log
	mv $DATE.private theenglishtuitioncorner.private
	mv $DATE.txt theenglishtuitioncorner.txt

# Update DNS
	## Extract the text
	TXTREC=`egrep -o '"[*a-zA-Z0-9;= +\/\\-]+"' theenglishtuitioncorner.txt | sed 's/"//g' | sed 's/*//g' | sed 's/h=rsa\-sha256;/h=sha256;/g' | awk '{print}' ORS=''`
	TXTDNSDATA='{"type":"TXT","name":"'$DATE'._domainkey","content":"'$TXTREC'"}'
	## https://stackoverflow.com/a/15580184

	## Send API request to cloudflare
	curl -X POST "https://api.cloudflare.com/client/v4/zones/$ZONE/dns_records" -H "X-Auth-Email: $AuthEmail" -H "X-Auth-Key: $AuthKey" -H "Content-Type: application/json" --data "$TXTDNSDATA" > cloudflareTXT.log

	## Test configuration
	opendkim-testkey -d theenglishtuitioncorner.com -s $DATE -k theenglishtuitioncorner.private -vvv > opendkimtest.log
	if [ $? -ne 0 ]; then
        ## Something went wrong --> Send email to the admins
        echo "Something went wrong rotating the DKIM keys, please check it out. Log is available at $DIR/opendkimtest.log. This is an automated message." | mail -s "DKIM Key Rotation Error" -r "$USER@theenglishtuitioncorner.com" "sunjerry019@gmail.com,liyicheng340@gmail.com"
        exit 1
    fi
fi

# Stop the server
	systemctl stop postfix opendkim

# Backup the previous key
	if [ ! -d "/etc/opendkim/keys/backups" ]; then
	  mkdir -p "/etc/opendkim/keys/backups"
	fi
	mv /etc/opendkim/keys/theenglishtuitioncorner.private /etc/opendkim/keys/backups/Backup_on_$DATE.private.bak

# Move the new key over
	cp theenglishtuitioncorner.private /etc/opendkim/keys/
	chown opendkim:opendkim /etc/opendkim/keys/*
	chmod go-rw /etc/opendkim/keys/*

# Replace the old values in opendkim key table
	echo -e "theenglishtuitioncorner\ttheenglishtuitioncorner.com:$DATE:/etc/opendkim/keys/theenglishtuitioncorner.private" > /etc/opendkim/key.table

# Restart the server
	systemctl start opendkim
	systemctl start postfix

# Send a test email to check if everything is working fine
	echo "This is an automated message to test if DKIM and SPF are working after a change of keys. The keys were changed on $(TZ=":Asia/Singapore" date '+%Y-%m-%d %H:%M:%S') Singapore Time. Please view the SPF and DKIM headers and rectify any errors should there be any. Remember to remove old system logfiles and DNS keys from time to time. To unsubscribe, please edit the cron-script directly." | mail -s "DKIM Key Rotation Test Email for $DATE" -r "$USER@theenglishtuitioncorner.com" "sunjerry019@gmail.com,liyicheng340@gmail.com"

# Clean up the working folder and compress logfiles for archiving
	cd $DIR/../
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on "$DATE.7z" "$DATE"
	if [ $? -ne 0 ]; then
		rm -r "$DATE"
	else
		echo "Failed to compress the logfiles for $DATE. Normally this email would not be sent, please rectify errors." | mail -s "Logfiles failed to compress for DKIM Key Rotation $DATE" -r "$USER@theenglishtuitioncorner.com" "sunjerry019@gmail.com,liyicheng340@gmail.com"
	fi
