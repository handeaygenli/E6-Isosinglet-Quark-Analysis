# E6-Isosinglet-Quark-Analysis

In this study, a C language implementation of CompHep infrastructure was used to analyse the E6 Isosinglet Quark. Kinematic distributions of jets, W boson and Z boson were studied. (p1p1->ZjWj1j1). This study requires the addition of E6 model files to the Comphep infrastructure. First of all, the files (txt file) produced in CompHep were converted to "lhe" format. This "lhe" file, which was also created with the ExRootLHEFConverter command, was converted to "ROOT" format.

Using the command LHEF->MakeClass("EAnalysisAnalysis"), the C and Header file of the ROOT file were created. To perform the analysis, the following commands are applied after the desired analysis codes are written in the C file.

.L ZtoEeAnalysis.C

ZtoEeAnalysis t

t.Loop()


# Jet Distributions

![Screenshot (16)](https://user-images.githubusercontent.com/62266472/206763901-53c45c79-bf20-4273-9c6b-8e249697d4fb.png)

# Jet Mass Distributions

![Screenshot (17)](https://user-images.githubusercontent.com/62266472/206763991-e4e53b34-3185-4596-a834-284c7595da6e.png)

# W Boson and Z Boson Distributions

![Screenshot (18)](https://user-images.githubusercontent.com/62266472/206764017-12ce08aa-663f-48df-b56c-180c6167b88f.png)

# W Boson and Z Boson Mass Distributions

![Screenshot (19)](https://user-images.githubusercontent.com/62266472/206764057-8e428632-b537-4211-9f7a-c61eacbb68c3.png)

