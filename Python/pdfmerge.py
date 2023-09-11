#Was trying out the PyPD2 library

from PyPDF2 import PdfMerger

# User input
pdf1 = input(r"Enter path of first file: ")
pdf2 = input(r"Enter path of second file: ")
outputFile = input(r"Enter path for the output merged file: ")

# Create object
merger = PdfMerger()

# Append the input PDF files one by one
merger.append(pdf1)
merger.append(pdf2)

# Write the merged PDF to the output path
merger.write(outputFile)

# Close the merger
merger.close()

print(f"Merged PDF saved to {outputFile}")


