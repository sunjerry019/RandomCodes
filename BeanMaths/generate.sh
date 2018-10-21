TC='\e['
Bold="${TC}1m"    # Bold text only, keep colors
Rst="${TC}0m"     # Reset all coloring and style
Purple="${TC}35m";


if [ $1 ]; then
	for (( i=1; i<=$1; i++ ))
	do
		./bean_2.py
		mv temp.pdf $i.pdf
	done
	echo -e "\n${Bold}${Purple}Output generated and saved as [numbers].pdf ${Rst}\n"
else
	./bean_2.py
	echo -e "\n${Bold}${Purple}Output generated as temp.pdf ${Rst}\n"
fi