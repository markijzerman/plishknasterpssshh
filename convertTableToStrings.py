import pandas as pd
import sys
import json
from unidecode import unidecode
import re

inFile = sys.argv[1]
outFile = "outfile.txt"
inp, = pd.read_html(inFile, header=0, parse_dates=["Language"])
inpDICT = inp.to_dict(orient="records")
inpJSON = inp.to_json(orient="records", date_format="iso")
jfile = json.loads(inpJSON)

f = open(outFile, "a")

for sound in jfile:
    for attribute, value in sound.items():
        if attribute == "Language":
            curLanguage = value
        else:
            curDefinition = attribute
            curSound = value
            curComplete = [curSound, curDefinition, curLanguage]
            if curComplete[0] != None: # als ie geen geluid heeft, print niet.
                # hier ook checken of er gekke karakters in zitten
                curComplete[0] = unidecode(curComplete[0]) #replace gekke karakters
                isItReadable = bool(re.match('^[a-zA-Z-()\s]+$', curComplete[0])) #laat nu alleen leesbare strings door
                if isItReadable == True:
                    s = curComplete[0]
                    findParenthesis = set('()') # vind tekst tussen haakjes
                    if any((c in findParenthesis) for c in curComplete[0]):
                        newString = s[s.find("(")+1:s.find(")")]
                        if len(newString) > 1: # als dit meer dan 1 karakter is, is het wrsch fijn en fonetisch
                            curComplete[0] = newString
                    # print (curComplete[0], curComplete[1], curComplete[2])
                    print ("%s (%s) (%s)" % (curComplete[0], curComplete[1], curComplete[2]))
                    f.write("%s (%s) (%s)\n" % (curComplete[0], curComplete[1], curComplete[2]))