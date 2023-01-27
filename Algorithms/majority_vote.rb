# Boyer-Moore Majority Vote Algorithm:
# The algorithm does not provide a guarantee
# when the data does not have a majority,
# returning a random value, then we need
# a step to check the result

def majority_vote(votes)
  count = 0
  most_voted = 0

  votes.each do |vote|
    most_voted = vote if count.zero?

    count += vote == most_voted ? 1 : -1
  end

  majority?(votes, most_voted) ? most_voted : -1
end

def majority?(votes, most_voted)
  counter = 0
  votes.each do |vote|
    counter += 1 if vote == most_voted
  end

  counter > votes.size / 2
end

puts majority_vote([1, 2, 3, 4, 5])
puts majority_vote([2, 2, 3, 4, 2])
puts majority_vote([])
