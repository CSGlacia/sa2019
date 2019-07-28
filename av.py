import hashlib
import os

path = os.getcwd() + "/malware/"
defs = os.getcwd() + "/definitions"
virs = os.getcwd() + "/virs"
# Populate heuristics.

def populateDefinitions(input):
    f = open(input, "r")
    d = []
    for lines in f:
        lines = lines.rstrip()
        d.append(lines)
    return d

def md5(file):
    f = open(file, "r")
    hasher = hashlib.md5()
    with open(file, "rb") as f:
        for data in iter(lambda: f.read(4096), b""):
            hasher.update(data)
    f.close()
    return hasher.hexdigest()

# With some filename FILE, test it against some known list L.
def lookup(definitions, f):
    inputHash = md5(f)
    for d in definitions:
        if (d == inputHash):
            return 1
    return 0

def heuristic(definitions, f):
    fil = open(f, "r")
    count = 0
    for lines in fil:
        lines = lines.rstrip()
        for l in definitions:
#            str = lines + " " + l
#            print(str)
            if (lines == l):
                count += 1
            if(l in lines):
                count += 0.5
    fil.close()
    return count

definitions = populateDefinitions(defs)
viruses = populateDefinitions(virs)

for filename in os.listdir(path):
    str = "Checked: " + filename
    f = path + filename

    if (lookup(viruses, f)):
        print("File " + filename + " is a known threat")
    analysis = heuristic(definitions, f)
    if (analysis >= 1):
        print("File " + filename + " could be a malicious script!")



# Keep command window open.
while (1):
    c = 1 + 1
