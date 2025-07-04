from django.shortcuts import render

# Create your views here.

def article_list(request):
    return render(request, 'articles/article_list.html')


def article_item(request, article_id):
    data = {"id": article_id}
    return render(request, 'articles/article_item.html', data)