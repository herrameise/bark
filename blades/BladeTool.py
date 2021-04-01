import os
import shutil
import sys

print("==================")
print(" BARK: Blade Tool")
print("==================")

blade_full = input("Full Name: ")
blade_author = input("Author: ")

blade_words = blade_full.split(' ')

blade_base = "".join(blade_words)
blade_core = blade_base + "Core"
blade_core_dll = blade_core + ".dll"
blade_core_so = blade_core + ".so"
blade_app = blade_base + "App"
blade_app_dll = blade_app + ".dll"
blade_app_so = blade_app + ".so"
blade_define = '_'.join(blade_words).upper()
blade_namespace = '_'.join(blade_words).lower()
blade_class = ''.join(blade_words)
blade_variable = '_'.join(blade_words).lower()
blade_forms = blade_base + "Forms"

print("Base:          %s" % blade_base)
print("Core:          %s" % blade_core)
print("Core DLL:      %s" % blade_core_dll)
print("Core SO:       %s" % blade_core_so)
print("App:           %s" % blade_app)
print("App DLL:       %s" % blade_app_dll)
print("App SO:        %s" % blade_app_so)
print("Define:        %s" % blade_define)
print("Namespace:     %s" % blade_namespace)
print("Class:         %s" % blade_class)
print("Variable:      %s" % blade_variable)
print("Forms:         %s" % blade_forms)

try:
    shutil.rmtree(blade_core)
except:
    pass

try:
    shutil.rmtree(blade_app)
except:
    pass

os.mkdir(blade_core)
os.mkdir(blade_app)



# BladeTemplateCore/Blade.cpp
fp = open("BladeTemplateCore/Blade.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
fp = open(blade_core + "/" + "Blade.cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateCore/Blade.h
fp = open("BladeTemplateCore/Blade.h", "r")
s = fp.read()
fp.close()
s = s.replace("BLADE_TEMPLATE", blade_define)
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
fp = open(blade_core + "/" + "Blade.h", "w")
fp.write(s)
fp.close()



# BladeTemplateCore/Loader.cpp
fp = open("BladeTemplateCore/Loader.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
s = s.replace("blade_template", blade_variable)
s = s.replace("name = \"Blade Template\"", "name = \"" + blade_full + "\"")
s = s.replace("author = \"DZ Labs\"", "author = \"" + blade_author + "\"")
fp = open(blade_core + "/" + "Loader.cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateCore/Loader.h
fp = open("BladeTemplateCore/Loader.h", "r")
s = fp.read()
fp.close()
s = s.replace("BLADE_TEMPLATE", blade_define)
fp = open(blade_core + "/" + "Loader.h", "w")
fp.write(s)
fp.close()



# BladeTemplateCore/Makefile
fp = open("BladeTemplateCore/Makefile", "r")
s = fp.read()
fp.close()
s = s.replace("BladeTemplateCore", blade_core)
fp = open(blade_core + "/" + "Makefile", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/Blade.cpp
fp = open("BladeTemplateApp/Blade.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
fp = open(blade_app + "/" + "Blade.cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/Blade.h
fp = open("BladeTemplateApp/Blade.h", "r")
s = fp.read()
fp.close()
s = s.replace("BLADE_TEMPLATE", blade_define)
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
fp = open(blade_app + "/" + "Blade.h", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/BladeTemplate.fbp
fp = open("BladeTemplateApp/BladeTemplate.fbp", "r")
s = fp.read()
fp.close()
s = s.replace("BladeTemplateForms", blade_forms)
s = s.replace("blade_template", blade_namespace)
fp = open(blade_app + "/" + blade_base + ".fbp", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/BladeTemplateForms.cpp
fp = open("BladeTemplateApp/BladeTemplateForms.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("BladeTemplateForms", blade_forms)
s = s.replace("blade_template", blade_namespace)
fp = open(blade_app + "/" + blade_forms + ".cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/BladeTemplateForms.h
fp = open("BladeTemplateApp/BladeTemplateForms.h", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
fp = open(blade_app + "/" + blade_forms + ".h", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/Loader.cpp
fp = open("BladeTemplateApp/Loader.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
s = s.replace("BladeTemplate", blade_class)
s = s.replace("blade_template", blade_variable)
fp = open(blade_app + "/" + "Loader.cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/Loader.h
fp = open("BladeTemplateApp/Loader.h", "r")
s = fp.read()
fp.close()
s = s.replace("BLADE_TEMPLATE", blade_define)
fp = open(blade_app + "/" + "Loader.h", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/MainPanel.cpp
fp = open("BladeTemplateApp/MainPanel.cpp", "r")
s = fp.read()
fp.close()
s = s.replace("blade_template", blade_namespace)
fp = open(blade_app + "/" + "MainPanel.cpp", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/MainPanel.h
fp = open("BladeTemplateApp/MainPanel.h", "r")
s = fp.read()
fp.close()
s = s.replace("BLADE_TEMPLATE", blade_define)
s = s.replace("BladeTemplateForms", blade_forms)
s = s.replace("blade_template", blade_namespace)
fp = open(blade_app + "/" + "MainPanel.h", "w")
fp.write(s)
fp.close()



# BladeTemplateApp/Makefile
fp = open("BladeTemplateApp/Makefile", "r")
s = fp.read()
fp.close()
s = s.replace("BladeTemplateForms", blade_forms)
s = s.replace("BladeTemplateApp", blade_app)
fp = open(blade_app + "/" + "Makefile", "w")
fp.write(s)
fp.close()