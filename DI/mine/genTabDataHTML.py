import sasdie
sasdie.init()
sasdie.record_execution("genTabDataHTML.py")
c = sasdie.Sasdie()

donnees = c.lireDescription()

textHTML = "<html><body>"
textHTML += "<h1>Sites classés</h1>"
textHTML += "<table border='1'>"
textHTML += "<tr><th>id</th><th>description</th><th>coordonnées</th><th>classification</th><th>justification</th></tr>"

for row in donnees:
    if str(row[0]).strip().lower() == "id":
        continue
    textHTML += "<tr>"
    textHTML += "<td>" + str(row[0]) + "</td>"
    textHTML += "<td>" + str(row[1]) + "</td>"
    textHTML += "<td>" + str(row[2]) + "</td>"
    textHTML += "<td>" + str(row[3]) + "</td>"
    textHTML += "<td>" + str(row[4]) + "</td>"
    textHTML += "</tr>"

textHTML += "</table>"
textHTML += "</body></html>"

c.publierpage_html(textHTML)
