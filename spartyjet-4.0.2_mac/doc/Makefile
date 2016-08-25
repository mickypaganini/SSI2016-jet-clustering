
STYLESHEET=SpartyJet_Documentation.css
EXTERNAL_STYLESHEET=SpartyJet_Documentation.css

THEDIR=html

doc:
	pdflatex SpartyJet_Documentation.tex
	pdflatex SpartyJet_Documentation.tex

#all : ${THEDIR} 
#	 latex2html -split 0 -dir ${THEDIR} -no_navigation  SpartyJet_Documentation.tex
#	@cp  SpartyJet_Documentation.css ${THEDIR}/SpartyJet_Documentation.css
#	@cp AlgorithmList.txt JetClasses.pdf ${THEDIR}/

${THEDIR} :
	@mkdir ${THEDIR} 