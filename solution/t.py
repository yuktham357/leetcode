import requests
import urllib3

urllib3.disable_warnings()

query_list_en = """
query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(
    categorySlug: $categorySlug
    limit: $limit
    skip: $skip
    filters: $filters
  ) {
    total: totalNum
    questions: data {
      acRate
      difficulty
      freqBar
      frontendQuestionId: questionFrontendId
      isFavor
      paidOnly: isPaidOnly
      status
      title
      titleSlug
      topicTags {
        name
        id
        slug
      }
      hasSolution
      hasVideoSolution
    }
  }
}
"""

question_list_query = {
    'operationName': 'problemsetQuestionList',
    'query': query_list_en,
    'variables': {
        'categorySlug': 'all-code-essentials',
        'filters': {"orderBy": "FRONTEND_ID", "sortOrder": "DESCENDING"},
        'limit': 10000,
        'skip': 0,
    },
}

# 获取所有题目 slugs
url_en = 'https://leetcode.com/graphql'
res = requests.post(url_en, json=question_list_query, timeout=20, verify=False)
