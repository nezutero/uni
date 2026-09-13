import requests

server = "http://ollama.a4.aqmo.org:8000"
model = "Qwen/Qwen3-4B-Instruct-2507"

def check_server(server):
    try:
        r = requests.get(server+'/v1/models', timeout=3)
        if r.status_code != 200:
            return False
        return True
    except:
        return False

def appel_api_rest_vllm(base_url, prompt):
    # Les paramètres de l'appel
    url = base_url + "/v1/chat/completions"
    payload = {
        "model": model,
        "messages": [ {"role": "user", "content": prompt} ],
            "stream": False
    }
    try:
        response = requests.post(
            url,
            json=payload,
            headers={"Content-Type": "application/json","Authorization": "Bearer none"}
        )
        data = response.json()
        response.raise_for_status()
        if 'choices' in data:
            return data['choices'][0]['message']['content']
        else:
            print(f"La réponse du service VLLM n'est pas celle attendue : {data}")
    except requests.exceptions.RequestException as e:
        print(f"Echec de l'appel au service VLLM: {str(e)}")

def main():
    if not check_server(server):
        print("Echec de la connexion avec le service VLLM, arrêt...")
        exit()
    rep = appel_api_rest_vllm(server, "En quelques lignes, qu'est-ce qu'un programme")
    print(rep)

if __name__=="__main__":
    main()

"""
Avant de rendre le code vous ajouterez ici la réponse obtenue en exécutant le code
"""
