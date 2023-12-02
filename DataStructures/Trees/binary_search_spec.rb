require_relative 'binary_search'
require 'pry'

RSpec.describe Trees::BinarySearch do
  let(:root) do
    Trees::Node.new(
      50,
      Trees::Node.new(
        25,
        Trees::Node.new(10),
        Trees::Node.new(40)
      ),
      Trees::Node.new(
        75,
        Trees::Node.new(60),
        Trees::Node.new(100)
      )
    )
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

      it 'inserts the element correctly when tree is empty' do
        tree.insert(4)

        expect(tree.root.key).to eql(4)
      end
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

      it 'returns nil' do
        expect(tree.successor(45)).to be_nil
      end
    end

    context 'when provides an element that is not present in the tree' do
      let(:root) { nil }

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

      it 'returns nil' do
        expect(tree.successor(45)).to be_nil
      end
    end

    context 'when provides an element that is not present in the tree' do
      let(:root) { nil }

      it 'returns nil' do
        expect(tree.successor(80)).to be_nil
      end
    end
  end
end
