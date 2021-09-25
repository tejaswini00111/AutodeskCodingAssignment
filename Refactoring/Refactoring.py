# Refactor code: Not timed (good to get it back within 24 hours)

# An intern has provided the code below to update the version number
# within two different files.
# The intern is has left and you need to review and improve the code before
# submitting to source control.
# Please do not be constrained by the existing code (i.e. you don't have
# to keep the same function names, structure)
# Aim for production quality 'best-practice/clean' code

# SCONSTRUCT file interesting lines
# config.version = Version(
# major=15,
# minor=0,
# point=6,
# patch=0
#)

"""


"""
import os
import re
import sys

def removeFile(path, file):
	"Removes a file from a given path"
	os.remove(os.path.join(path, file))
	print("Removed file: ", os.path.join(path, file))
	
def renameFile(oldPath, oldFile, newPath, newFile):
	"Renames a file"
	os.rename(os.path.join(oldPath, oldFile), os.path.join(newPath, newFile))
	print("Renamed file from ", os.path.join(oldPath, oldPath), " to ", os.path.join(newPath, newFile))

def updateContentsInFile(path, file):
	"Update the version number by incrementing the previous version"
	versionNumber = 0
	grantReadWriteExecuteAccess(path, file)
	
	#Creating a new file for writing can be avoided by loading file data into memory
	fin = open(os.path.join(path, file), 'r')
	fout = open(os.path.join(path, file) + "Modified", 'w')
	for line in fin:
		if "point=" in line:
			versionNumber = int(line[8:-2]) + 1
			line = re.sub("point\=[\d]+","point=" + str(versionNumber), line)
		fout.write(line)
			
	fin.close()
	fout.close()
	removeFile(path, file)
	renameFile(path, file + "Modified", path, file)
	return str(versionNumber)

# VERSION file interesting line
# ADLMSDK_VERSION_POINT=6 
def updateVersionNumberInFile(path, file, versionNumber):
	"Update the build number in the VERSION file"
	grantReadWriteExecuteAccess(path, file)
    
	#Creating a new file for writing can be avoided by loading file data into memory
	fin = open(os.path.join(path, file), 'r')
	fout = open(os.path.join(path, file + "Modified"), 'w')
	for line in fin:
		line = re.sub("ADLMSDK_VERSION_POINT\=[\d].*","ADLMSDK_VERSION_POINT=" + versionNumber, line)
		fout.write(line)
		
	fin.close()
	fout.close()
	removeFile(path,file)
	renameFile(path, file + "Modified", path, file)

def grantReadWriteExecuteAccess(path, file):
	"Grants permission for reading and writing to files"
	os.chmod(os.path.join(path, file), 0o777)

def validateFileExists(path, file):
	"Validates if given path and file exists"
	if os.path.isdir(path):
		if os.path.exists(os.path.join(path, file)):
			print("File: ", file, " exists at path: ", path)
		else:
			print("ERROR: file: ", file, " doesn't exist at path: ", path);
			sys.exit(1)
	else:
		print("ERROR: path: ", path, " doesn't exist");
		sys.exit(1)
	
def main():
	inputPath = input('Please provide the input path of the file to be updated: ')
	inputFile = input('Please provide the filename whose version to be updated: ')
	versionFile = input('Please provide the name of the Version file to be updated: ')

	#Validating if the files exist
	validateFileExists(inputPath, inputFile)
	validateFileExists(inputPath, versionFile)

	#Update the contents of the file with the right version number
	versionNumber = updateContentsInFile(inputPath, inputFile)
	
	#Update the version number in the file
	updateVersionNumberInFile(inputPath, versionFile, versionNumber)

if __name__ == "__main__":
    main()
