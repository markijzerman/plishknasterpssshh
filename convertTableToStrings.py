import pandas as pd
import sys
import numpy as np
import json

inFile = sys.argv[1]
outFile = "outfile.json"
inp, = pd.read_html(inFile, header=0, parse_dates=["Language"])
inpDICT = inp.to_dict(orient="records")
inpJSON = inp.to_json(orient="records", date_format="iso")
jfile = json.loads(inpJSON)

for sound in jfile:
    for attribute, value in sound.items():
        if attribute == "Language":
            curLanguage = value
        else:
            curDefinition = attribute
            curSound = value
            curComplete = [curSound, curDefinition, curLanguage]
            # hier er een nieuwe dict van maken en checken of iets None is.
            # print (curComplete)
            if curComplete[0] != None:
                print (curSound, curDefinition, curLanguage)