import pandas as pd
import sys
import numpy as np

inFile = sys.argv[1]
outFile = "outfile.json"
inp, = pd.read_html(inFile, header=0, parse_dates=["Language"])
inpJSON = inp.to_json(orient="records", date_format="ascii")

print(inp.values[0][0]) # FOR every language, [1][0] is 2nd language
print(inp.values[0][1]) # FOR every sound
print(inp.keys()[1]) # is the definition (same as second part of value)
print("-------------------")
print("-------------------")
print("-------------------")



x = 0
i = 0
for language in inp.values[:,0]: # for every language
    print("-------------------")
    print(language)
    print(inp.values[x,1]) # for every sound. 1 should walk over to get all sounds
    print(inp.keys()[1]) # should iterate over that 3


    x = x + 1


# f = open(outFile, "a")
# print(inp)
# f.write(inpJSON)

# for i in np.nditer(inp.values.transpose(), flags = ["refs_ok"]):
#     print(i)
#     # print(inp.values[0][1])
