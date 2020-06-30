"
I wrap the following cmake command

 cmake --help-command add_subdirectory
add_subdirectory
----------------

Add a subdirectory to the build.

::

 add_subdirectory(source_dir [binary_dir]
                  [EXCLUDE_FROM_ALL])

Add a subdirectory to the build.  The source_dir specifies the
directory in which the source CMakeLists.txt and code files are
located.  If it is a relative path it will be evaluated with respect
to the current directory (the typical usage), but it may also be an
absolute path.  The binary_dir specifies the directory in which to
place the output files.  If it is a relative path it will be evaluated
with respect to the current output directory, but it may also be an
absolute path.  If binary_dir is not specified, the value of
source_dir, before expanding any relative path, will be used (the
typical usage).  The CMakeLists.txt file in the specified source
directory will be processed immediately by CMake before processing in
the current input file continues beyond this command.

If the EXCLUDE_FROM_ALL argument is provided then targets in the
subdirectory will not be included in the ALL target of the parent
directory by default, and will be excluded from IDE project files.
Users must explicitly build targets in the subdirectory.  This is
meant for use when the subdirectory contains a separate part of the
project that is useful but not necessary, such as a set of examples.
Typically the subdirectory should contain its own project() command
invocation so that a full build system will be generated in the
subdirectory (such as a VS IDE solution file).  Note that inter-target
dependencies supercede this exclusion.  If a target built by the
parent project depends on a target in the subdirectory, the dependee
target will be included in the parent project build system to satisfy
the dependency.

"
Class {
	#name : #CMakeAddSubDirectory,
	#superclass : #CMakeTemplate,
	#instVars : [
		'sourcedir',
		'binarydir',
		'excludefromall'
	],
	#category : #'CMakeVMMakerSqueak-CMakeTemplates'
}

{ #category : #'initialize-release' }
CMakeAddSubDirectory >> initialize [
	sourcedir :=  'source_dir'.
	binarydir :=	 '[binary_dir]'.
	excludefromall := '[EXCLUDE_FROM_ALL]'.
	self content:'  add_subdirectory (',sourcedir, '  ' ,binarydir, '  ' , excludefromall,  ')'

]

{ #category : #accessing }
CMakeAddSubDirectory >> sourcedir: sString [
	sourcedir := '"', (sString copyReplaceAll: '"' with: '\"'), '"'.
	self content:'  add_subdirectory (',sourcedir,')'
]

{ #category : #accessing }
CMakeAddSubDirectory >> sourcedir: sString binarydir: bString excludefromall: eString [
	sourcedir := sString.
	binarydir :=	 bString.
	excludefromall := eString.
	self content:'  add_subdirectory (',sourcedir, '  ' ,binarydir, '  ' , excludefromall,  ')'

]