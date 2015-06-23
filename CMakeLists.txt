cmake_minimum_required (VERSION 2.6)

project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

set(EXECUTABLE_OUTPUT_PATH ~/workspace/SpaceEngine/bin)

#add_executable(Tutorial
#	src/main.cpp
#	src/Object.cpp
#	src/Ship.cpp
#	src/BattleCruiser.cpp
#	src/Equipement.cpp
#	src/InputManager.cpp
#	src/DataReader.cpp
#	)

#Génération de la liste des fichiers sources
file(
	GLOB_RECURSE
	source_files
	src/*
)

#Déclaration de l'exécutable
add_executable(
	my_exe
	${source_files}
)
