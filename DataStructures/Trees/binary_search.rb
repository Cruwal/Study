module Trees
  class Node
    attr_reader :key
    attr_accessor :left, :right, :parent

    def initialize(key, left: nil, right: nil, parent: nil)
      @key = key
      @left = left
      @right = right
      @parent = parent
    end
  end

  class BinarySearch
    attr_reader :root

    def initialize(root = nil)
      @root = root
    end

    def insert(element)
      return @root = Node.new(element) if empty?

      node = root
      until node.nil?
        parent = node
        node = element < node.key ? node.left : node.right
      end

      new_node = Node.new(element, parent: parent)
      element < parent.key ? parent.left = new_node : parent.right = new_node
    end

    def search(element)
      node = root
      until node.nil?
        return node if node.key == element

        node = element < node.key ? node.left : node.right
      end

      nil
    end

    def maximum(node = @root)
      node = node.right until node&.right.nil?

      node
    end

    def minimum(node = @root)
      node = node.left until node&.left.nil?

      node
    end

    def successor(element)
      return if empty?

      node = search(element)

      return minimum(node.right) if node&.right

      while node.parent
        return node.parent if node.parent.left == node

        node = node.parent
      end

      nil
    end

    def predecessor(element)
      return if empty?

      path = search_with_path(element)
      node = path.last[:element]

      return maximum(node.left) if node&.left

      while node.parent
        return node.parent if node.parent.right == node

        node = node.parent
      end

      nil

    end

    private

    def search_with_path(element, node = @root)
      path = []

      until node.nil?
        if node.key == element
          path << { element: node, direction: nil }

          return path
        end

        direction = element < node.key ? 'left' : 'right'
        path << { element: node, direction: direction }

        node = node.send(direction)
      end

      path
    end

    def empty?
      @root.nil?
    end
  end
end
