import sasdie
sasdie.init()
sasdie.record_execution("carte.py")
c = sasdie.Sasdie()

c.creerCarte()

csvdp = c.lireDonneesPollution("data-pm-sasdie-bus.csv")

CIRCLE_DIAMETER_M = 20

total_pm25 = 0.0
nb_mesures = 0

for row in csvdp:
    try:
        vblon = float(row[0])
        vblat = float(row[1])
        velon = float(row[2])
        velat = float(row[3])
        value = float(row[6])
    except ValueError:
        continue

    avg_lon = (vblon + velon) / 2
    avg_lat = (vblat + velat) / 2
    c.macarte.ajoutCercleSurLaCarte(avg_lon, avg_lat,
                                     CIRCLE_DIAMETER_M,
                                     str(round(value, 2)))

    total_pm25 += value
    nb_mesures += 1

moyenne_pm25 = total_pm25 / nb_mesures

mairie_lat = 48.1113
mairie_lon = -1.6800

c.macarte.ajoutCercleSurLaCarte(mairie_lon, mairie_lat,
                                 500,
                                 str(round(moyenne_pm25, 2)))

csvcs = c.lireCoordonneesGPS()

for row in csvcs:
    longitude = float(row[0])
    latitude = float(row[1])
    label = str(row[2]) if len(row) > 2 else "Bar/Restaurant"
    c.macarte.ajoutMarqueurSurLaCarte(longitude, latitude, label)

Parcs_Jardins = c.lectureDescriptions()

for row in Parcs_Jardins:
    if str(row[0]).strip().lower() == "id":
        continue

    classification = str(row[3]).strip().lower()

    coord_str = str(row[2]).strip().strip("[]")
    lat_str, lon_str = coord_str.split(",")
    lat = float(lat_str)
    lon = float(lon_str)

    if classification == "parc et jardin":
        c.macarte.ajoutParcJardinSurLaCarte(lon, lat, "Parc et jardin")
    elif classification == "musée":
        c.macarte.ajoutMuseeSurLaCarte(lon, lat, "Musée")

cartehtml = c.macarte.produireHTMLCarte()
c.serveur.publierpage_html(cartehtml)
