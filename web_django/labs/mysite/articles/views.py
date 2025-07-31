from django.contrib.auth.decorators import login_required
from django.shortcuts import render
from .models import Article
# Create your views here.

def article_list(request):
    articles = Article.objects.all().order_by('date')
    return render(request, 'articles/article_list.html', {'articles': articles})


def article_item(request, slug):
    article = Article.objects.get(slug=slug)
    return render(request, 'articles/article_item.html', {'article': article})


@login_required(login_url='accounts:login')
def article_create(request):
    return render(request, 'accounts/article_create.html')