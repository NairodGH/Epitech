import Levenshtein
from fastapi import HTTPException


def normalize_city_name(city_name):
    city_name = city_name.lower()
    city_name = city_name.replace("st", "saint")
    city_name = city_name.replace("-", " ")
    return city_name

def compare_common_char(input_city: str, target_city: str) -> float:
    input_city = normalize_city_name(input_city)
    target_city = normalize_city_name(target_city)

    score = 0
    for i, input_char in enumerate(input_city):
        if i < len(target_city) and input_char == target_city[i]:
            score += 1
    return score / len(input_city)

def custom_similarity_score(input_city, target_city):
    input_city = normalize_city_name(input_city)
    target_city = normalize_city_name(target_city)

    lev_distance = Levenshtein.distance(input_city, target_city)
    max_len = max(len(input_city), len(target_city))
    normalized_lev = 1 - (lev_distance / max_len)

    edit_operations = Levenshtein.editops(input_city, target_city)
    matching_blocks = Levenshtein.matching_blocks(edit_operations, input_city, target_city)
    total_matching_chars = sum(block[2] for block in matching_blocks)

    max_len = max(len(input_city), len(target_city))
    matching = (total_matching_chars / max_len)
    final_score = (normalized_lev + matching) / 2
    return final_score


def search_match(input_city, target_cities):
    # filter target_cities list with first letter
    target_cities = [city for city in target_cities if input_city[0].lower() == city[0].lower()]

    matches = []
    max_score = 0
    for city in target_cities:

        score = compare_common_char(input_city, city)
        if score > max_score:
            matches = [(city, score)]
            max_score = score
        elif score == max_score:
            matches.append((city, score))

    # Case: one value with high score
    if len(matches) == 1 and matches[0][1] >= 0.80:
        return matches[0][0]

    # Case: multiple high score
    elif len(matches) > 1 and matches[0][1] >= 0.80:
        for i in matches:
            print(f"Resultat pour la ville : {i}, len = {len(i[0])}")
            if len(i[0]) == len(input_city):
                return i[0]
        result = str([match[0].capitalize() for match in matches])
        result = result.replace("[", "").replace("]", "").replace("'", "")
        raise HTTPException(
            status_code=404,
            detail=f"Plusieurs gares trouvées, merci de saisir une gare valide parmi : {result}"
        )

    # Case: one or multiple results with low score:
    elif matches[0][1] < 0.80:
        best_city = ""
        best_score = 0

        for city in target_cities:
            scores = custom_similarity_score(input_city, city)
            # print(f"scores : {scores} pour la ville : {city}")
            if scores > best_score:
                best_score = scores
                best_city = city
        if best_score >= 0.80:
            return best_city
        else:
            raise HTTPException(
            status_code=403,
            detail="Impossibilité de tracer l'itinéraire. Merci de vérifier les informations fournies dans votre requête"
            )
    else:
        raise HTTPException(
            status_code=403,
            detail="Impossibilité de tracer l'itinéraire. Merci de vérifier les informations fournies dans votre requête"
        )