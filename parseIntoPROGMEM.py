stringNr = 0

outFile = "PROGMEMOUT.txt"

f = open(outFile, "w")

with open("ALL_ONO_lesser.txt", "r") as ins:
    mylines = ins.read().splitlines()
    array = []
    for line in mylines:
        # print(line)
        print("const char string_%s[] PROGMEM = " % stringNr + "\"" + line + "\";")
        f.write("const char string_%s[] PROGMEM = " % stringNr + "\"" + line + "\";\n")
        # array.append(line)
        stringNr = stringNr + 1

f.write("\n")

f.write("int numOfStrings = %s;\n" % stringNr)

f.write("\n")

f.write("const char * const string_table[] PROGMEM =\n")
f.write("{\n")

for i in range (0, stringNr):
        print("string_%s," % i)
        f.write("string_%s,\n" % i)

f.write("};")