class Solution(object):
		def maxProductPath(self, grid):
			rows = len(grid)
			cols = len(grid[0])			
			keep = {}


			def recurse(rows, cols):
#if we already have the solution we can just return it
				
				if (rows, cols) in keep:
					print "from memo"
					return keep[(rows,cols)]
# base case when we have reached the final recursive path
				if rows == 0 and cols == 0:
					print "base case"
					ans = grid[rows][cols], grid[rows][cols]
#recursive step: if our indexes are > 0 we decrement and go again
				else:
					minmaxarr = []
# move downward     
					if rows > 0:
						print "rows"
						downward = recurse(rows-1, cols)
						minmaxarr.extend([downward[0]*grid[rows][cols], downward[1]*grid[rows][cols]]) 
# move to the right
					if cols > 0:
						print "cols"
						right = recurse(rows, cols-1)
						minmaxarr.extend([right[0]*grid[rows][cols], right[1]*grid[rows][cols]])
# like in other solution we must keepo both max and min, python makes this easy 
					ans = max(minmaxarr), min(minmaxarr)
#add solution to memoized list

				keep[(rows,cols)] = ans
				return ans

			ans = recurse(rows-1, cols-1)

			if ans[0] >= 0:
			    return ans[0] % (10**9+7)
			else:
			    return -1
