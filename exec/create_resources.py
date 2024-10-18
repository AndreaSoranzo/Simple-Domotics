import os

with open("app/resources.qrc","w") as qrc:
    qrc.write("<!DOCTYPE RCC><RCC version=\"1.0\">\n")
    qrc.write("<qresource>\n")

    for dir in os.listdir("app/assets"):
        for item in os.listdir("app/assets/" + dir):
            if("svg" in item):
                qrc.write(f"<file>assets/icons/{item}</file>\n")
            if("png" in item or "jpg" in item):
                qrc.write(f"<file>assets/images/{item}</file>\n")
            if("qss" in item):
                qrc.write(f"<file>assets/qss/{item}</file>\n")
            if("ttf" in item):
                qrc.write(f"<file>assets/fonts/{item}</file>\n")

    qrc.write("</qresource>\n")
    qrc.write("</RCC>\n")



