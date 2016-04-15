#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/comsci/GObject.o \
	${OBJECTDIR}/src/comsci/supports/macros/char_type.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libopengsi-dynamic-cpp.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libopengsi-dynamic-cpp.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libopengsi-dynamic-cpp.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/comsci/GObject.o: src/comsci/GObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comsci
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comsci/GObject.o src/comsci/GObject.cpp

${OBJECTDIR}/src/comsci/supports/macros/char_type.o: src/comsci/supports/macros/char_type.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comsci/supports/macros
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -include include/opengsi/comsci/supports/macros/char_type.h -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comsci/supports/macros/char_type.o src/comsci/supports/macros/char_type.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libopengsi-dynamic-cpp.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
