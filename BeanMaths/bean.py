#!/bin/python3

"""
To generate questions that involve operations of numbers between l_limit and h_limit
"""

import random
from subprocess import call
import os

# <customizations>
operators = ["\\times"]
l_limit = 6
h_limit = 9
no_of_probs = 50
no_of_cols = 4
itemsep = "2.3\\baselineskip" #0.45 for 100, 2.3 for 50
vfill = True
show = False
# </customizations>

problems = []
operatorMap = {"+": "+", "-": "-", "\\times": "*", "\\div": "/"}
nameMap = {"+": "Addition", "-": "Subtraction", "\\times": "Multiplication", "\\div": "Division"}

out = open("temp.tex","w")

def getTypes():
	ausgabe = []
	for op in operators:
		ausgabe.append(nameMap[op])
		ausgabe.append(", ")
	ausgabe = ausgabe[:-1]

	if len(operators) > 1:
		ausgabe[-2] = " and "

	return "".join(ausgabe)

def sortNum(x, y):
	return (x, y) if (x > y) else (y, x)

def ans(evalProb):
	evalProb[1] = operatorMap[evalProb[1]]
	return eval("".join(evalProb))

for i in range(no_of_probs):
	while True:
		a = random.randint(l_limit,h_limit)
		b = random.randint(l_limit,h_limit)

		if (a - b) != 0:
			break

	op = random.choice(operators)

	if op is "-":
		(a,b) = sortNum(a,b)

	problems.append([str(a), op, str(b)])

out.write("\\documentclass[11pt]{article}\\usepackage[a4paper,margin=0.90in,tmargin=0.5in]{geometry}\\usepackage{amsmath, amsthm, amssymb}\n")
out.write("\\usepackage[type1]{libertine}\n")
out.write("\\usepackage{multicol}\n")
out.write("\\usepackage{enumitem}")
out.write("\\usepackage[usenames,dvipsnames,svgnames,table]{xcolor}")

out.write("\\newcommand{\\addstretch}[1]{\\addtolength{#1}{\\fill}}\n")

#out.write("\\title{Maths Practice (Addition and Subtractions)}\n")
out.write("\\title{{Maths Practice ({})}}\n".format(getTypes()))
out.write("\\raggedbottom\n")

out.write("\\begin{document}\n")

out.write("\\maketitle\n")

#out.write("\\addstretch{\\baselineskip}\n\\addstretch{\\abovedisplayskip}\n\\addstretch{\\abovedisplayshortskip}\n\\addstretch{\\belowdisplayskip}\n\\addstretch{\\belowdisplayshortskip}\n\\addstretch{\\itemsep}")

out.write("\\begin{{multicols{}}}{{{}}}\n".format("*" if vfill else "", no_of_cols))
# out.write("\\raggedcolumns")
out.write("\\begin{{enumerate}}[itemsep={}]\n".format(itemsep))

for prob in problems:
	out.write("\\item ${} =$ \n".format(" ".join(prob)))

out.write("\\end{enumerate}\n")
out.write("\\vfill\n" if vfill else "") 
out.write("\\end{{multicols{}}}\n".format("*" if vfill else ""))

out.write("\\newpage")

out.write("\\vspace{\\baselineskip}\n\\begin{center}\n{\\Huge Answers}\n\end{center}\n\\vspace{0.5\\baselineskip}")

out.write("\\begin{{multicols{}}}{{{}}}\n".format("*" if vfill else "", no_of_cols))
# out.write("\\raggedcolumns")
out.write("\\begin{{enumerate}}[itemsep={}]\n".format(itemsep))

for prob in problems:
	out.write("\\item ${} = {{ \\color[rgb]{{0,0,1}} {} }}$ \n".format(" ".join(prob), ans(prob)))

out.write("\\end{enumerate}\n")
out.write("\\vfill\n" if vfill else "") 
out.write("\\end{{multicols{}}}\n".format("*" if vfill else ""))

out.write("\\end{document}\n")

out.close()

fdir = os.path.dirname(os.path.realpath(__file__))
call(["pdflatex", "-output-directory=" + fdir, "temp.tex"])
call(["rm", os.path.join(fdir, "temp.aux"), os.path.join(fdir, "temp.log")])
if show:
	call(["evince", os.path.join(fdir, "temp.pdf")])