---
layout: default
title: Group Members
permalink: /group/
english_only: true
---

## Group Members
{: .group-page-heading }

Meet the students in our group.
{: .group-intro }

{% for category in site.data.group.groups %}
<h3>{{ category.title }}</h3>
<div class="member-grid">
{% for member in category.members %}
  {% assign portrait = member.gender | default: 'neutral' | prepend: '/images/students/default-' | append: '.svg' %}
  {% if member.photo %}{% assign portrait = member.photo %}{% endif %}
  <article class="member">
    <img class="member-photo" src="{{ portrait | relative_url }}" alt="Portrait of {{ member.name | escape }}" width="88" height="88" loading="lazy">
    <div>
      <h4 class="member-name">{{ member.name | escape }}</h4>
      {% if member.cohort %}<p class="member-detail">Cohort {{ member.cohort }}</p>{% endif %}
      {% if member.joined %}<p class="member-detail">Joined {{ member.joined }}</p>{% endif %}
    </div>
  </article>
{% endfor %}
</div>
{% endfor %}
