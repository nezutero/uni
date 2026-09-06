#Exercice de classification
import json
import requests
#from typing import List, Dict, Any, Tuple, Optional
from pydantic import BaseModel, Field, ValidationError, field_validator
from openai import OpenAI

server = 'http://ollama.a4.aqmo.org:8000/v1'

class ThemeAnalysis(BaseModel):
    """Modèle pour les réponses d'analyse thématique"""
    is_relevant: bool
    explanation: str

    
def check_server(server):
    try:
        r = requests.get(server+'/models', timeout=3)
        if r.status_code != 200:
            return False
        print("Available Models")
        print(r.json())
        return True
    except Exception:
        return False
    return True

def lectureDescriptions():
    chemin_fichier = 'description.json'
    try:
        with open(chemin_fichier, 'r') as fichier:
            donnees = json.load(fichier)
    except FileNotFoundError:
        print("Le fichier n'a pas été trouvé.")
        exit()
    except json.JSONDecodeError:
        print("Erreur de décodage JSON.")
        exit()
    return donnees

def ecritureDuFichierCSV(contenuFichier):
    chemin_fichier = 'analyse.csv'
    try:
        with open(chemin_fichier, 'w') as fichier:
            fichier.write(contenuFichier)
    except Exception as e:
        print(f"Erreur dans ecritureDuFichierCSV {e}.")
        return False
    return True

def classifier_oai(description, theme):
    client = OpenAI(api_key='none', base_url=server)
    response = client.beta.chat.completions.parse(
        model="meta-llama/Llama-3.2-3B-Instruct",
        messages=[
            {"role": "system", "content": "You are a text analysis assistant. You always answer in JSON."},
            {"role": "user", "content": f'Ce résumé : "{description}" te semble-t-il relatif à ce thème: {theme}.'}
        ],
        response_format=ThemeAnalysis,
    )
    return response.choices[0].message.content


def main():
    if not check_server(server):
        print("cannot connect to server Ollama, exiting...")
        exit()

    donnees = lectureDescriptions()

    # Boucle sur chaque élément pour classification
    res = ""
    for item in donnees:
        description = item['description']
        ident = item['id']
        themes = ["parc et jardin", "musée"]
        for theme in themes:
            resp = classifier_oai(description, theme)
            print(ident, theme, resp)
            res = res + str(resp)
    ecritureDuFichierCSV(res)

if __name__ =="__main__":
    main()
