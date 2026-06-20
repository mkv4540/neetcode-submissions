import heapq
class Twitter:

    def __init__(self):
        self.follow_table = {}
        self.post_table = {}
        self.count = 0
        self.news_feed_table = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.post_table:
            self.post_table[userId] = []
        self.count = self.count + 1
        self.post_table[userId].append((tweetId, self.count)) 

    def feed_order(self, newsFeed: dict):
        finalFeed = []
        feeds = []
        if len(newsFeed) == 0:
            return []
        for key, val in newsFeed:
            heapq.heappush(finalFeed, (val, key))
            if len(finalFeed) > 10:
                heapq.heappop(finalFeed)
        finalFeed.sort()
        finalFeed.reverse()
        for key, val in finalFeed:
            feeds.append(val)
        return feeds
    def getNewsFeed(self, userId: int) -> List[int]:
        newsFeed = []
        finalFeed = []
        feeds = []
        if userId in self.post_table:
            newsFeed.extend(self.post_table[userId])
        if userId not in self.follow_table:
            return self.feed_order(newsFeed)
        for followeeId in self.follow_table[userId]:
            newsFeed.extend(self.post_table[followeeId])
        return self.feed_order(newsFeed)
        
    def follow(self, followerId: int, followeeId: int) -> None:
        if followeeId == followerId:
            return
        if followerId not in self.follow_table:
            self.follow_table[followerId] = set()
        self.follow_table[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.follow_table:
            return
        if followeeId in self.follow_table[followerId]:
            self.follow_table[followerId].remove(followeeId)
        
