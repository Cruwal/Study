BASE_STRING = 'bananal'

# O(text * pattern)
def find_pattern_on_base_string(text, pattern)
  counter = 0
  positions = []

  last_possible_character = text.size - pattern.size
  while counter <= last_possible_character
    positions << counter if text[counter] == pattern[0] && pattern == text[counter...(counter + pattern.size)]

    counter += 1
  end

  positions
end

puts find_pattern_on_base_string(BASE_STRING, 'ana')
