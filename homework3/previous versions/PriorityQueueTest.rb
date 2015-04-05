require 'minitest/autorun'
require './priorityqueue.rb'

class PriorityQueueTest < MiniTest::Test

  def test_new
    q = PriorityQueue.new
    assert_equal(q.peek, nil)
    assert_raises(RuntimeError) {q.remove!}
  end

  # Add 1..100 in at random, they should come out in order
  def test_adds_and_removes
    q = PriorityQueue.new
    (1..100).to_a.sort_by {rand}.each {|x| q.add!(x)}
    1.upto(100) do |i|
      assert_equal(q.peek, i)
      q.remove!
    end
  end
end