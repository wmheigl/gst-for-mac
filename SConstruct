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

#env.Append(CPPPATH=['/opt/local/include'])
#env.Append(LIBPATH=['/opt/local/lib'])

# print(env.Dump())

SConscript('lib/SConscript', variant_dir='build/lib', exports='env')
SConscript('src/SConscript', variant_dir='build/src', exports='env')

