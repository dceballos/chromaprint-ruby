require 'mkmf'
dir_config("/usr/local/lib")
find_library("chromaprint", "chromaprint_new", "/usr/local/lib")
create_makefile('chromaprint/chromaprint')
