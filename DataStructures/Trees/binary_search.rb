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

    def delete(element)
      return if empty?

      node = search(element)

      return if node&.key != element

      return transplant(node, node.right) if node.left.nil?
      return transplant(node, node.left) if node.right.nil?

      node_successor = successor(element)
      if node_successor != node.right
        transplant(node_successor, node_successor.right)

        node_successor.right = node.right
        node_successor.right.parent = node_successor
      end

      transplant(node, node_successor)
      node_successor.left = node.left
      node_successor.left.parent = node_successor
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

      node = search(element)

      return maximum(node.left) if node&.left

      while node.parent
        return node.parent if node.parent.right == node

        node = node.parent
      end

      nil
    end

    def in_order_traversal(node = @root, response = [])
      unless node.nil?
        in_order_traversal(node.left, response)
        response << node.key
        in_order_traversal(node.right, response)
      end

      response
    end

    def pre_order_traversal(node = @root, response = [])
      unless node.nil?
        response << node.key
        pre_order_traversal(node.left, response)
        pre_order_traversal(node.right, response)
      end

      response
    end

    def post_order_traversal(node = @root, response = [])
      unless node.nil?
        post_order_traversal(node.left, response)
        post_order_traversal(node.right, response)
        response << node.key
      end

      response
    end

    private

    def transplant(node_a, node_b)
      return @root = node_b if root == node_a

      node_a.parent.left == node_a ? node_a.parent.left = node_b : node_a.parent.right = node_b
    end

    def empty?
      @root.nil?
    end
  end
end
