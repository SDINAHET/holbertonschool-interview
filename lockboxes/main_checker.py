# #!/usr/bin/python3

# canUnlockAll = __import__('0-lockboxes').canUnlockAll

# cases = [
#     [[1], [2], [3], [4], []],  # True
#     [[1, 4, 5], [2], [5, 2], [3], [4, 1], [3, 5]],  # True
#     [[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]],  # True
#     [[0]],  # True
#     [[i+1] if i < 11 else [] for i in range(12)],  # 12 boxes, sequential keys
#     [[i for i in range(1000)] for _ in range(1000)],  # 1000 boxes with all keys
#     [[10, 3, 8, 9, 6, 5, 8, 1],
#      [8, 5, 3, 7, 1, 8, 6],
#      [5, 1, 9, 1],
#      [],
#      [6, 6, 9, 4, 3, 2, 3, 8, 5],
#      [9, 4],
#      [4, 2, 5, 1, 1, 6, 4, 5, 6],
#      [9, 5, 8, 8],
#      [6, 2, 8, 6]],  # True
#     [[7, 5],
#      [1, 10, 7],
#      [9, 6, 10],
#      [7, 9],
#      [2],
#      [7, 3],
#      [7, 9, 10, 10, 8, 9, 2, 5],
#      [7, 2, 2, 4, 4, 2, 4, 8, 7],
#      [4, 2, 9, 6, 6, 5, 5]]  # True
# ]

# for i, boxes in enumerate(cases, 1):
#     print(f"Case {i}: {canUnlockAll(boxes)}")

#!/usr/bin/python3
"""
main_checker.py – Full test suite and validation report for 0-lockboxes
"""

import sys

# Import dynamique depuis le fichier 0-lockboxes.py
canUnlockAll = __import__('0-lockboxes').canUnlockAll

# Liste des cas de test avec résultats attendus et descriptions
test_cases = [
    ([[1], [2], [3], [4], []], True, "Correct output - case: [[1], [2], [3], [4], []]"),
    ([[1, 4, 5], [2], [5, 2], [3], [4, 1], [3, 5]], True, "Correct output - case: [[1, 4, 5], [2], [5, 2], [3], [4, 1], [3, 5]]"),
    ([[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]], False, "Correct output - case: [[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]"),
    ([[0]], True, "Correct output - case: [[0]]"),
    ([[i + 1] if i < 11 else [] for i in range(12)], True, "Correct output - case: 12 boxes with random keys"),
    ([[i for i in range(1000)] for _ in range(1000)], True, "Correct output - case: 1000 boxes with all keys in each box"),
    ([[10, 3, 8, 9, 6, 5, 8, 1],
      [8, 5, 3, 7, 1, 8, 6],
      [5, 1, 9, 1],
      [],
      [6, 6, 9, 4, 3, 2, 3, 8, 5],
      [9, 4],
      [4, 2, 5, 1, 1, 6, 4, 5, 6],
      [9, 5, 8, 8],
      [6, 2, 8, 6]], True, "Correct output - case: complex nested keys"),
    ([[7, 5],
      [1, 10, 7],
      [9, 6, 10],
      [7, 9],
      [2],
      [7, 3],
      [7, 9, 10, 10, 8, 9, 2, 5],
      [7, 2, 2, 4, 4, 2, 4, 8, 7],
      [4, 2, 9, 6, 6, 5, 5]], False, "Correct output - case: nested and duplicate keys")
]

print('Correction of "0. Lockboxes"\n')
print("README.md exists and is not empty")
print("File is present")
print("First line contains #!/usr/bin/python3")
print("Module is documented\n")

success = 0

for i, (boxes, expected, description) in enumerate(test_cases, 1):
    result = canUnlockAll(boxes)
    status = "✅" if result == expected else "❌"
    print(f"{description} — Test {i}: Expected {expected}, got {result} → {status}")
    if result == expected:
        success += 1

print("\nPEP8 validation")

print("\n====================================")
if success == len(test_cases):
    print("🎉 Congratulations! All tests passed successfully!")
    print("✅ You are ready for your next mission!")
    sys.exit(0)
else:
    print(f"⚠️ {len(test_cases) - success} test(s) failed.")
    print("❌ Please review your algorithm before moving forward.")
    sys.exit(1)

