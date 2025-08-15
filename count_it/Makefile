.PHONY: all pep8 test test-unit test-integration test-requirements test-meta help
PY   = python3
# Utilise pycodestyle si dispo, sinon pep8
PEP8 ?= $(shell command -v pycodestyle >/dev/null 2>&1 && echo pycodestyle || echo pep8)

all: pep8 test

## ---- Qualité ----
pep8:
	$(PEP8) 0-count.py

## ---- Tests ----
test:
	$(PY) -m unittest -v

test-unit:
	$(PY) -m unittest -v test_unit_0_count.py

test-integration:
	$(PY) -m unittest -v test_integration_0_count.py

test-requirements:
	$(PY) -m unittest -v test_requirements_0_count.py

test-meta:
	$(PY) -m unittest -v test_meta_0_count.py

help:
	@echo "make            -> pep8 + tous les tests"
	@echo "make pep8       -> PEP8 sur 0-count.py"
	@echo "make test       -> tous les tests (découverte unittest)"
	@echo "make test-unit  -> tests unitaires"
	@echo "make test-integration -> tests d'intégration"
	@echo "make test-requirements -> tests des exigences"
	@echo "make test-meta  -> tests méta (shebang, README, imports)"
```

Test makefile dans le terminal
```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# make              # pep8 + tous les tests
make pep8
make test
make test-integration
pycodestyle 0-count.py
python3 -m unittest -v
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok
test_file_exists (test_meta_0_count.TestMeta) ... ok
test_first_line_shebang (test_meta_0_count.TestMeta) ... ok
test_imports_alpha_order (test_meta_0_count.TestMeta) ... ok
test_readme_exists (test_meta_0_count.TestMeta) ... ok
test_desc_sort_then_alpha_ties_and_skip_zero (test_requirements_0_count.TestRequirements)
Sorted by count desc, then alpha; words with zero -> skipped; ... ok
test_duplicates_sum_multiplicity (test_requirements_0_count.TestRequirements)
Duplicates in word_list sum (multiplicity). ... ok
test_invalid_subreddit_prints_nothing (test_requirements_0_count.TestRequirements)
Invalid subreddit -> non-200 -> print nothing. ... ok
test_no_redirects_flag_is_false (test_requirements_0_count.TestRequirements)
Ensure allow_redirects=False is passed to requests.get. ... ok
test_occurrence_based_not_titles (test_requirements_0_count.TestRequirements)
Counts occurrences, not titles: 'java java java' -> 3. ... ok
test_prototype_callable_two_args (test_requirements_0_count.TestRequirements)
Prototype callable: def count_words(subreddit, word_list). ... ok
test_punctuation_not_counted (test_requirements_0_count.TestRequirements)
java., java!, java_ do NOT count as 'java'. ... ok
test_case_insensitive_keywords_and_duplicates (test_unit_0_count.TestCountWordsUnit)
'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled. ... ok
test_exact_tokens_punctuation_ignored (test_unit_0_count.TestCountWordsUnit)
Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'. ... ok
test_invalid_subreddit_status_302 (test_unit_0_count.TestCountWordsUnit)
If subreddit invalid -> 302/404 etc., print nothing. ... ok
test_no_matches_prints_nothing (test_unit_0_count.TestCountWordsUnit)
If no keyword occurrences -> print nothing. ... ok
test_recursion_across_pages (test_unit_0_count.TestCountWordsUnit)
Ensure we follow 'after' and aggregate counts across pages (recursive). ... ok

----------------------------------------------------------------------
Ran 20 tests in 0.158s

OK
pycodestyle 0-count.py
python3 -m unittest -v
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok
test_file_exists (test_meta_0_count.TestMeta) ... ok
test_first_line_shebang (test_meta_0_count.TestMeta) ... ok
test_imports_alpha_order (test_meta_0_count.TestMeta) ... ok
test_readme_exists (test_meta_0_count.TestMeta) ... ok
test_desc_sort_then_alpha_ties_and_skip_zero (test_requirements_0_count.TestRequirements)
Sorted by count desc, then alpha; words with zero -> skipped; ... ok
test_duplicates_sum_multiplicity (test_requirements_0_count.TestRequirements)
Duplicates in word_list sum (multiplicity). ... ok
test_invalid_subreddit_prints_nothing (test_requirements_0_count.TestRequirements)
Invalid subreddit -> non-200 -> print nothing. ... ok
test_no_redirects_flag_is_false (test_requirements_0_count.TestRequirements)
Ensure allow_redirects=False is passed to requests.get. ... ok
test_occurrence_based_not_titles (test_requirements_0_count.TestRequirements)
Counts occurrences, not titles: 'java java java' -> 3. ... ok
test_prototype_callable_two_args (test_requirements_0_count.TestRequirements)
Prototype callable: def count_words(subreddit, word_list). ... ok
test_punctuation_not_counted (test_requirements_0_count.TestRequirements)
java., java!, java_ do NOT count as 'java'. ... ok
test_case_insensitive_keywords_and_duplicates (test_unit_0_count.TestCountWordsUnit)
'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled. ... ok
test_exact_tokens_punctuation_ignored (test_unit_0_count.TestCountWordsUnit)
Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'. ... ok
test_invalid_subreddit_status_302 (test_unit_0_count.TestCountWordsUnit)
If subreddit invalid -> 302/404 etc., print nothing. ... ok
test_no_matches_prints_nothing (test_unit_0_count.TestCountWordsUnit)
If no keyword occurrences -> print nothing. ... ok
test_recursion_across_pages (test_unit_0_count.TestCountWordsUnit)
Ensure we follow 'after' and aggregate counts across pages (recursive). ... ok

----------------------------------------------------------------------
Ran 20 tests in 0.178s

OK
python3 -m unittest -v test_integration_0_count.py
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok

----------------------------------------------------------------------
Ran 4 tests in 0.101s

OK
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it#
```


Tableau
| Type de testTest                                          | Vérifie                                                                 | Entrées simulées                                                                                  | Attendu                                                                                           |
|----------------|-----------------------------------------------|--------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| Integration    | test_valid_subreddit_list1                    | Subreddit valide + **pagination** + **tri**                              | 2 pages (after → puis None) avec titres: python, javascript, react, java, scala                  | `python: 4`, `javascript: 3`, `react: 3`, `java: 2`, `scala: 2` (ordre exact)                    |
| Integration    | test_valid_subreddit_case_insensitive         | **Casse insensible** (mots-clés + titres)                                | 1 page: “Python PYTHON python”, “React”; keywords `["PYTHON","react"]`                           | `python: 3`, `react: 1`                                                                           |
| Integration    | test_valid_subreddit_duplicates_in_list       | **Doublons** dans `word_list` ⇒ multiplicité                             | 1 titre: “java javascript java”; keywords `["JavA","java"]`                                      | `java: 4` (2 occurrences × multiplicité 2)                                                       |
| Integration    | test_invalid_subreddit_list1                  | Subreddit **invalide** ⇒ **rien n’est imprimé**                          | Statut HTTP 404                                                                                  | Sortie vide                                                                                       |
| Unit           | test_exact_tokens_punct_ignored               | **Token exact** ; ponctuation **non comptée**                            | Titres: “java java. java! java_ javascript”, …                                                   | `python: 3`, `react: 3`, `scala: 2`, `java: 1`, `javascript: 1`                                   |
| Unit           | test_case_insensitive_and_duplicates          | **Casse** + **doublons**                                                 | “java javascript java”; keywords `["JavA","java"]`                                               | `java: 4`                                                                                        |
| Unit           | test_recursion_across_pages                   | **Récursivité** via `after` (agrégation multi-pages)                     | 2 pages chaînées (after = "t3_next" puis None)                                                   | `python: 4`, `javascript: 3`, `react: 3`, `java: 2`, `scala: 2`                                   |
| Unit           | test_invalid_subreddit_status_302             | **Redirect**/non-200 ⇒ **rien**                                          | Statut 302                                                                                       | Sortie vide                                                                                       |
| Unit           | test_no_matches_prints_nothing                | **Aucun match** ⇒ **rien**                                               | Titre: “golang rust typescript”; keywords `["python","java"]`                                    | Sortie vide                                                                                       |
| Requirements   | test_desc_sort_then_alpha_ties_and_skip_zero  | **Tri count↓ puis alpha** ; **skip 0** ; **minuscule**                    | “alpha alpha”, “beta beta”; keywords `["beta","alpha","GAMMA"]`                                  | `alpha: 2`, `beta: 2` (gamma ignoré)                                                             |
| Requirements   | test_duplicates_sum_multiplicity              | Somme des **doublons**                                                   | “java javascript java”; keywords `["JavA","java"]`                                               | `java: 4`                                                                                        |
| Requirements   | test_invalid_subreddit_prints_nothing         | Subreddit **invalide** ⇒ **rien**                                        | Statut 404                                                                                       | Sortie vide                                                                                       |
| Requirements   | test_no_redirects_flag_is_false               | `allow_redirects=False` passé à `requests.get`                           | Appel inspecté via mock                                                                           | Paramètre présent et à `False`                                                                    |
| Requirements   | test_occurrence_based_not_titles              | **Occurrences**, pas le nombre de titres                                 | “java java java”                                                                                 | `java: 3`                                                                                        |
| Requirements   | test_prototype_callable_two_args              | Prototype **appelable** avec 2 args                                      | Appel `count_words("programming", ["java"])`                                                     | Pas d’exception (exécution OK)                                                                    |
| Requirements   | test_punctuation_not_counted                  | `java.`, `java!`, `java_` **non comptés**                                | Titres: “java. java! java_ java,” + “java”                                                       | `java: 1`                                                                                        |
| Meta           | test_file_exists                              | Fichier **présent**                                                      | Présence de `0-count.py`                                                                          | OK                                                                                                |
| Meta           | test_first_line_shebang                       | 1ʳᵉ ligne = `#!/usr/bin/python3`                                         | Lecture de la 1ʳᵉ ligne                                                                           | OK                                                                                                |
| Meta           | test_imports_alpha_order                      | **Ordre alphabétique** des imports                                       | Parcours des lignes `import`/`from`                                                               | OK                                                                                                |
| Meta           | test_readme_exists                            | Présence du **README.md**                                                | Fichier `README.md` dans `count_it/`                                                              | OK                                                                                                |

Explications (3 lignes par test)
Integration / test_valid_subreddit_list1
• Contexte : agrégation de plusieurs pages /hot avec pagination.
• Simulation : 2 pages mockées avec after puis fin.
• Validation : total par mot, tri count↓ puis A→Z, ordre exact attendu.

Integration / test_valid_subreddit_case_insensitive
• Contexte : casse indifférente pour mots-clés et titres.
• Simulation : titres mixtes “Python/PYTHON/python”, “React”.
• Validation : python: 3, react: 1.

Integration / test_valid_subreddit_duplicates_in_list
• Contexte : mots dupliqués dans word_list s’additionnent.
• Simulation : keywords ["JavA","java"] + deux “java” dans le titre.
• Validation : java: 4 (2 × multiplicité 2).

Integration / test_invalid_subreddit_list1
• Contexte : subreddit invalide.
• Simulation : réponse HTTP 404.
• Validation : aucune sortie (comportement silencieux).

Unit / test_exact_tokens_punct_ignored
• Contexte : compter uniquement les tokens nus.
• Simulation : “java.”/“java!”/“java_” présents mais ignorés.
• Validation : seul java nu est compté ; ordre final attendu.

Unit / test_case_insensitive_and_duplicates
• Contexte : casse + doublons.
• Simulation : 2 occurrences de java et multiplicité 2.
• Validation : java: 4.

Unit / test_recursion_across_pages
• Contexte : appel récursif via after.
• Simulation : 2 pages chaînées.
• Validation : sommes cumulées et tri correct.

Unit / test_invalid_subreddit_status_302
• Contexte : redirection/non-200.
• Simulation : statut 302 (redirect).
• Validation : sortie vide (on ne suit pas la redirection).

Unit / test_no_matches_prints_nothing
• Contexte : aucun mot-clé trouvé.
• Simulation : titres sans les mots suivis.
• Validation : aucune ligne imprimée.

Requirements / test_desc_sort_then_alpha_ties_and_skip_zero
• Contexte : tri count↓ puis A→Z + skip des zéros + minuscules.
• Simulation : alpha=2, beta=2, gamma=0.
• Validation : alpha: 2, beta: 2; gamma absent.

Requirements / test_duplicates_sum_multiplicity
• Contexte : règle des doublons (addition).
• Simulation : ["JavA","java"] + 2 “java”.
• Validation : java: 4.

Requirements / test_invalid_subreddit_prints_nothing
• Contexte : subreddit invalide.
• Simulation : statut 404.
• Validation : sortie vide.

Requirements / test_no_redirects_flag_is_false
• Contexte : ne pas suivre les redirections.
• Simulation : inspection des kwargs du mock requests.get.
• Validation : allow_redirects=False.

Requirements / test_occurrence_based_not_titles
• Contexte : compter les occurrences, pas les titres.
• Simulation : “java java java”.
• Validation : java: 3.

Requirements / test_prototype_callable_two_args
• Contexte : prototype compatible avec 2 arguments.
• Simulation : appel count_words("programming", ["java"]).
• Validation : aucune exception levée.

Requirements / test_punctuation_not_counted
• Contexte : ponctuation non comptée.
• Simulation : “java. java! java_ java,” + “java”.
• Validation : java: 1.

Meta / test_file_exists
• Contexte : structure du projet.
• Simulation : présence de 0-count.py.
• Validation : OK.

Meta / test_first_line_shebang
• Contexte : exécutable Python.
• Simulation : lecture de la 1ʳᵉ ligne.
• Validation : #!/usr/bin/python3.

Meta / test_imports_alpha_order
• Contexte : style des imports.
• Simulation : comparaison triée des lignes import.
• Validation : ordre alphabétique.

Meta / test_readme_exists
• Contexte : documentation minimale requise.
• Simulation : présence de README.md.
• Validation : OK.

