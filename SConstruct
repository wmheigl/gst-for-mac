# Setup main SConstruct with these features:
# - driver/library structure
# - separate build directory
# - hierarchical build
# - check for presence of required programs: flex, bison, gperf
# - check for presence of required libraries and their header files
#   gnutls, ltdl, ffi, sigsegv, 
# - better yet: eliminate dependence on Gnu libraries, use Darwin equivalents

# env = Environment()
# print(env.Dump())

EnsurePythonVersion(3, 11)
EnsureSConsVersion(4, 4)

# Check for CommandLineTools
import os
if not os.path.isdir("/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"):
    print("CommandLineTools not installed!")
    print("To install:  xcode-select --install")
    Exit(1)

env = Environment()
conf = Configure(env)

# Checks for libraries, header files, etc. go here!
## no need to check for libraries that ship with OSX and CommandLineTools
## check for the GNU stuff

# used in src/libgst or src/libaux
if not conf.CheckLibWithHeader('sigsegv', 'sigsegv.h', language='c'):
    print('Did not find libsigsegv, exiting!')
    Exit(1)
if not conf.CheckLibWithHeader('gmp', 'gmp.h', language='c'):
    print('Did not find libgmp, required by gnutls, exiting!')
    Exit(1)
if not conf.CheckLibWithHeader('ltdl', 'ltdl.h', language='c'):
    print('Did not find libltdl, exiting!')
    Exit(1)

    print('Did not find liblightning, exiting!')
    Exit(1)

env = conf.Finish()

########################################################################
# Libraries
########################################################################

#env.Append(CPPPATH=['/opt/local/include'])
#env.Append(LIBPATH=['/opt/local/lib'])

# add libraries that ship with MacOSX SDK
env.Append(LIBS=['ffi', 'pthread', 'poll'])

# add 3rd party libraries, already handled in env.Configure
#env.Append(LIBS=['gmp', 'ltdl', 'sigsegv'])

# add project directories with header files
env.Append(CPPPATH=['#src', '#src/libaux', '#src/libgst', '#src/snprintfv', '#src/util/superops', '#lib/logc/include'])

# add project libraries
env.Append(LIBS=['aux', 'gst', 'snprintfv'])
env.Append(LIBPATH=['#build/src/libgst', '#build/src/libaux', '#build/src/snprintfv'])

# print(env.Dump())

# build executables
SConscript('lib/SConscript', variant_dir='build/lib', exports='env')
SConscript('src/SConscript', variant_dir='build/src', exports='env')
SConscript('test/SConscript', variant_dir='build/test', exports='env')

