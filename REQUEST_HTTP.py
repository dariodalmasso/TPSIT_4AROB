import requests

r = requests.get("https://www.itiscuneo.edu.it")
f = open("./Prova.html", "w")
f.write(r.text)
print(r.text)
f.close()