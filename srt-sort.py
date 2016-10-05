# Sort srt subtitle entries by time
# (C) 2011 g/christensen (gchristnsn@gmail.com)

# Launch this script in a directory containing srt subtitles
# or pass the directory name as an argument

import os 
import sys
import re
import glob

class Bunch:
    __init__ = lambda self, **kw: setattr(self, '__dict__', kw)

def timing2pos(timing):
    m = re.match(r'(\d{2}):(\d{2}):(\d{2}),(\d{3})\s*-->', timing)
    pos = int(m.group(1)) * 216000000
    pos += int(m.group(2)) * 3600000
    pos += int(m.group(3)) * 1000
    pos += int(m.group(4))
    return pos
   
def collect_record(lines):
    record = Bunch(pos=0, timing='', text=[])
    lines.pop(0)
    record.pos = timing2pos(lines[0])
    record.timing = lines.pop(0)
    while lines[0] != '':
        record.text.append(lines.pop(0))
    return record

def collect_records(lines):
    result = list()
    while len(lines) > 0:
        if re.match(r'^\d+$', lines[0]):
            result.append(collect_record(lines))
        else:
            lines.pop(0) 
    return result

def print_records(records, to_file):
    ctr = 1
    sys.stdout = open(to_file, 'w')
    for rec in records:
        print ctr
        ctr += 1
        print rec.timing
        for text in rec.text:
            print text
        print ''
    sys.stdout = sys.__stdout__

def process_file(file_name):
    srt_file = open(file_name)
    srt_lines = srt_file.read().splitlines()
    srt_records = collect_records(srt_lines)
    srt_file.close()
    srt_records.sort(lambda u,v: u.pos - v.pos)
    print_records(srt_records, file_name)

def process_directory(dir_name):
    for f in glob.glob(dir_name + '/*.srt'):
        print 'processing file: ' + f
        process_file(f)

if __name__ == '__main__':
    dir = sys.argv[1] if len(sys.argv) > 1 else os.getcwd()
    process_directory(dir)