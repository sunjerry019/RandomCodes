pdftk {1..20}.pdf cat output combined.pdf
pdftk combined.pdf cat 1-endodd output questions.pdf
pdftk combined.pdf cat 1-endeven output answers.pdf
