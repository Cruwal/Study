require_relative 'binary_search'
require 'pry'

RSpec.describe Trees::BinarySearch do
  let(:root) { Trees::Node.new(50) }
  let(:root_left) { Trees::Node.new(25) }
  let(:root_right) { Trees::Node.new(75) }
  let(:root_left_left) { Trees::Node.new(10) }
  let(:root_left_right) { Trees::Node.new(40) }
  let(:root_right_left) { Trees::Node.new(60) }
  let(:root_right_right) { Trees::Node.new(100) }

  let!(:node_connections) do
    root.left = root_left
    root.right = root_right
    root_left.parent = root
    root_right.parent = root

    root_left.left = root_left_left
    root_left.right = root_left_right
    root_left_left.parent = root_left
    root_left_right.parent = root_left

    root_right.left = root_right_left
    root_right.right = root_right_right
    root_right_left.parent = root_right
    root_right_right.parent = root_right
  end

  #         50
  #     25       75
  #
  # 10     40   60   100

  let(:tree) { described_class.new(root) }

  context '#insert' do
    it 'inserts the element correctly when tree is not empty' do
      tree.insert(7)
      tree.insert(15)
      tree.insert(31)
      tree.insert(45)
      tree.insert(55)
      tree.insert(65)
      tree.insert(80)
      tree.insert(101)

      expect(tree.root.left.left.left.key).to eql(7)
      expect(tree.root.left.left.right.key).to eql(15)
      expect(tree.root.left.right.left.key).to eql(31)
      expect(tree.root.left.right.right.key).to eql(45)
      expect(tree.root.right.left.left.key).to eql(55)
      expect(tree.root.right.left.right.key).to eql(65)
      expect(tree.root.right.right.left.key).to eql(80)
      expect(tree.root.right.right.right.key).to eql(101)
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'inserts the element correctly when tree is empty' do
        tree.insert(4)

        expect(tree.root.key).to eql(4)
      end
    end
  end

  context '#delete' do
    it 'deletes the nodes correctly' do
      tree.delete(10)

      expect(tree.root.key).to eql(50)
      expect(tree.root.left.key).to eql(25)
      expect(tree.root.right.key).to eql(75)
      expect(tree.root.left.left).to be_nil
      expect(tree.root.left.right.key).to eql(40)
      expect(tree.root.right.left.key).to eql(60)
      expect(tree.root.right.right.key).to eql(100)

      tree.delete(25)

      expect(tree.root.key).to eql(50)
      expect(tree.root.left.key).to eql(40)
      expect(tree.root.right.key).to eql(75)
      expect(tree.root.left.left).to be_nil
      expect(tree.root.left.right).to be_nil
      expect(tree.root.right.left.key).to eql(60)
      expect(tree.root.right.right.key).to eql(100)

      tree.delete(50)

      expect(tree.root.key).to eql(60)
      expect(tree.root.left.key).to eql(40)
      expect(tree.root.right.key).to eql(75)
      expect(tree.root.left.left).to be_nil
      expect(tree.root.left.right).to be_nil
      expect(tree.root.right.left).to be_nil
      expect(tree.root.right.right.key).to eql(100)

      tree.delete(75)

      expect(tree.root.key).to eql(60)
      expect(tree.root.left.key).to eql(40)
      expect(tree.root.right.key).to eql(100)
      expect(tree.root.left.left).to be_nil
      expect(tree.root.left.right).to be_nil
      expect(tree.root.right.left).to be_nil
      expect(tree.root.right.right).to be_nil

      tree.delete(60)

      expect(tree.root.key).to eql(100)
      expect(tree.root.left.key).to eql(40)
      expect(tree.root.right).to be_nil
      expect(tree.root.left.left).to be_nil
      expect(tree.root.left.right).to be_nil

      tree.delete(100)

      expect(tree.root.key).to eql(40)
      expect(tree.root.left).to be_nil
      expect(tree.root.right).to be_nil

      tree.delete(40)

      expect(tree.root).to be_nil
    end

    it 'returns nil when try to delete an element that is not present in the tree' do
      expect(tree.delete(700)).to be_nil
    end
  end

  context '#search' do
    it 'returns the correct element when tree is not empty' do
      expect(tree.search(50).key).to eql(50)
      expect(tree.search(25).key).to eql(25)
      expect(tree.search(10).key).to eql(10)
      expect(tree.search(40).key).to eql(40)
      expect(tree.search(60).key).to eql(60)
      expect(tree.search(100).key).to eql(100)
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.search(4)).to be_nil
      end
    end

    context 'when the provided element is not present on the tree' do
      it 'returns nil' do
        expect(tree.search(1)).to be_nil
      end
    end
  end

  context '#minimum' do
    it 'returns the correct minimum when tree is not empty' do
      expect(tree.minimum.key).to eql(10)
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.minimum).to be_nil
      end
    end
  end

  context '#maximum' do
    it 'returns the correct minimum when tree is not empty' do
      expect(tree.maximum.key).to eql(100)
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.minimum).to be_nil
      end
    end
  end

  context '#successor' do
    it 'returns the correct successor when tree is not empty' do
      expect(tree.successor(50).key).to eql(60)
      expect(tree.successor(25).key).to eql(40)
      expect(tree.successor(75).key).to eql(100)
      expect(tree.successor(10).key).to eql(25)
      expect(tree.successor(40).key).to eql(50)
      expect(tree.successor(60).key).to eql(75)
      expect(tree.successor(100)).to be_nil
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.successor(45)).to be_nil
      end
    end

    context 'when provides an element that is not present in the tree' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.successor(80)).to be_nil
      end
    end
  end

  context '#predecessor' do
    it 'returns the correct predecessor when tree is not empty' do
      expect(tree.predecessor(50).key).to eql(40)
      expect(tree.predecessor(25).key).to eql(10)
      expect(tree.predecessor(75).key).to eql(60)
      expect(tree.predecessor(40).key).to eql(25)
      expect(tree.predecessor(60).key).to eql(50)
      expect(tree.predecessor(100).key).to eql(75)
      expect(tree.predecessor(10)).to be_nil
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.successor(45)).to be_nil
      end
    end

    context 'when provides an element that is not present in the tree' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns nil' do
        expect(tree.successor(80)).to be_nil
      end
    end
  end

  context '#in_order_traversal' do
    it 'returns the elements in order' do
      expect(tree.in_order_traversal).to eql([10, 25, 40, 50, 60, 75, 100])
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns an empty array' do
        expect(tree.in_order_traversal.empty?).to eql(true)
      end
    end
  end

  context '#pre_order_traversal' do
    it 'returns the elements in pre order' do
      expect(tree.pre_order_traversal).to eql([50, 25, 10, 40, 75, 60, 100])
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns an empty array' do
        expect(tree.pre_order_traversal.empty?).to eql(true)
      end
    end
  end

  context '#post_order_traversal' do
    it 'returns the elements in post order' do
      expect(tree.post_order_traversal).to eql([10, 40, 25, 60, 100, 75, 50])
    end

    context 'when tree is empty' do
      let(:root) { nil }
      let!(:node_connections) { nil }

      it 'returns an empty array' do
        expect(tree.post_order_traversal.empty?).to eql(true)
      end
    end
  end
end
