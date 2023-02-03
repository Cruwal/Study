# O(text * pattern)
def find_pattern_on_base_string(text, pattern)
  counter = 0
  positions = []

  last_possible_character = text.size - pattern.size
  while counter <= last_possible_character
    text_local_index = counter
    pattern_index = 0

    while pattern_index < pattern.size && text[text_local_index] == pattern[pattern_index]
      text_local_index += 1
      pattern_index += 1
    end

    positions << counter if pattern_index == pattern.size

    counter += 1
  end

  positions
end

puts find_pattern_on_base_string('bananal', 'ana')
