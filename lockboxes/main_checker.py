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

canUnlockAll = __import__('0-lockboxes').canUnlockAll
# from 0-lockboxes import canUnlockAll  # ou utilise __import__ si besoin

test_cases = [
    # (boxes, expected_result)
    ([[1], [2], [3], [4], []], True),
    ([[1, 4, 5], [2], [5, 2], [3], [4, 1], [3, 5]], True),
    ([[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]], False),
    ([[0]], True),
    ([[i + 1] if i < 11 else [] for i in range(12)], True),
    ([[i for i in range(1000)] for _ in range(1000)], True),
    ([[10, 3, 8, 9, 6, 5, 8, 1],
      [8, 5, 3, 7, 1, 8, 6],
      [5, 1, 9, 1],
      [],
      [6, 6, 9, 4, 3, 2, 3, 8, 5],
      [9, 4],
      [4, 2, 5, 1, 1, 6, 4, 5, 6],
      [9, 5, 8, 8],
      [6, 2, 8, 6]], True),
    ([[7, 5],
      [1, 10, 7],
      [9, 6, 10],
      [7, 9],
      [2],
      [7, 3],
      [7, 9, 10, 10, 8, 9, 2, 5],
      [7, 2, 2, 4, 4, 2, 4, 8, 7],
      [4, 2, 9, 6, 6, 5, 5]], False)
]

print("Correction of \"0. Lockboxes\"")
print("Running detailed test report...\n")

success = 0

for i, (boxes, expected) in enumerate(test_cases, 1):
    result = canUnlockAll(boxes)
    status = "✅ PASS" if result == expected else "❌ FAIL"
    print(f"Test case {i}: Expected {expected}, got {result} → {status}")
    if result == expected:
        success += 1

# Résumé final
if success == len(test_cases):
    print("\n🎉 Congratulations! All tests passed successfully!")
    print("✅ You are ready for your next mission!")
else:
    print(f"\n⚠️ {len(test_cases) - success} test(s) failed.")
    print("❌ Please review your algorithm before moving forward.")

# Optionnel : exit non-zero code if failure (pour GitHub Actions)
import sys
if success != len(test_cases):
    sys.exit(1)
