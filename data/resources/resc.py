import csv

import sqlite3

db = sqlite3.connect('resc.db')
c = db.cursor()

c.execute('''CREATE TABLE resource(
             name,
             resc_type,
             staffing,
             start_time,
             end_time,
             start_day,
             end_day,
             start_season,
             end_season,
             disploc,
             volume,
             severity,
             fpu,
             fixed,
             borrowable,
             agency)''')

sql = '''INSERT INTO resource VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)'''


fin = open('ResourcesFinal.csv', 'rb')
cin = csv.reader(fin)
i = 0
c.execute('BEGIN')
for line in cin:
    i += 1
#changes,resource name,resource type,staffing,shift start time,shift end time,
#start day,end day,season start day,season end day,dipatch location,% avail,
#daily cost,hourly cost,water volume (gal),severity resource,
#full time employees (FTE),number of positions,annual costs,vehicle costs,
#fpu,fixed location,borrowable,agency,If HELI attached Helicopter,
#Question/Comments
    if i < 2:
        continue
    try:
        name = line[1]
        t = line[2]
        staff = int(line[3])
        try:
            st_time = int(line[4])
        except:
            st_time = 800
        try:
            end_time = int(line[5])
        except:
            end_time = 1800
        try:
            sday = int(line[6])
        except:
            sday = 0
        try:
            eday = int(line[7])
        except:
            eday = 6
        try:
            seas_start = int(line[8])
        except:
            seas_start = 1
        try:
            seas_end = int(line[9])
        except:
            seas_end = 365
        loc = line[10]
        p = int(line[11])
        dcost = float(line[12])
        hcost = float(line[13])
        vol = int(line[14])
        severity = 0 if line[15] == 'n' else 1
        fte = float(line[16])
        npos = int(line[17])
        ycost = int(line[18])
        vcost = int(line[19])
        fpu = line[20]
        fixed = int(line[21])
        borrow = int(line[22])
        agency = line[23]
        hel = line[24]
        c.execute(sql, (name, t, staff, st_time, end_time, sday, eday, seas_start,
                        seas_end, loc, vol, severity, fpu, fixed, borrow, agency))
        print(i)
    except:
        for j, l in enumerate(line):
            print(j, l)
        raise

fin.close()
db.commit()

print(i)
