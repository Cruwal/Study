def insertion_sort(array)
  i = 1
  # outer loop
  while i < array.length
    key = array[i]
    j = i - 1

    # inner loop
    while j >= 0 && array[j] > key
      array[j + 1] = array[j]
      j -= 1
    end

    array[j + 1] = key
    i += 1
  end

  array
end

print insertion_sort([3, 5, 1, 7, -2, 0, 9, 8, 4, -5])

# Analysis
# Worst Case:
# outer loop: n
# inner loop: 1, 2, 3, 4, 5, ..., n
# O(n²)

# Best Case:
# outer loop: n
# inner loop: 1, 1, 1, 1, 1, 1, ...
# Ω(n)
