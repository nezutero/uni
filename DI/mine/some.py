donnees = c.lireDescription()

tableau = "<table border='1'>\n"

tableau += "<tr><th>id</th><th>description</th><th>coordonnées</th><th>classification</th><th>justification</th></tr>\n"

for row in donnees:
    tableau += "<tr>"
    tableau += "<td>" + str(row[0]) + "</td>"
    tableau += "<td>" + str(row[1]) + "</td>"
    tableau += "<td>" + str(row[2]) + "</td>"
    tableau += "<td>" + str(row[3]) + "</td>"
    tableau += "<td>" + str(row[4]) + "</td>"
    tableau += "</tr>\n"

tableau += "</table>\n"

textHTML = "<h1>Sites classés</h1>\n" + tableau

c.publierpage_html(textHTML)

with open("description.html", "w") as f:
    f.write(textHTML)
