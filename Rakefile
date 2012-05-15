# -*- ruby -*-

require 'rubygems'
require 'rubygems/package_task'
require 'rake/extensiontask'

spec = Gem::Specification.new do |s| 
  s.name = "chromaprint"
  s.summary = "Chromaprint ruby bindings"
  s.authors = 'Daniel Ceballos, Adam Rachman'
  s.version = '0.0.1'
  s.platform = Gem::Platform::RUBY
  s.files = Dir.glob('lib/*.{rb,so,bundle}') 
  s.extensions = FileList["ext/chromaprint/extconf.rb"]
end

Gem::PackageTask.new(spec) do |pkg|
end

Rake::ExtensionTask.new('chromaprint', spec) do |ext|
  ext.lib_dir = 'lib/chromaprint/'
end
