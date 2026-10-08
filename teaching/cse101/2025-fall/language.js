(() => {
  const storageKey = 'cse101-language';
  const textElements = document.querySelectorAll('[data-en]');
  const labeledElements = document.querySelectorAll('[data-label-en]');
  const buttons = document.querySelectorAll('[data-language]');
  const description = document.querySelector('meta[name="description"]');
  const chineseDescription = description.content;

  textElements.forEach(element => { element.dataset.zh = element.textContent; });
  labeledElements.forEach(element => { element.dataset.labelZh = element.getAttribute('aria-label'); });

  function setLanguage(language, updateUrl = false) {
    document.documentElement.lang = language === 'en' ? 'en' : 'zh-CN';
    textElements.forEach(element => { element.textContent = element.dataset[language]; });
    labeledElements.forEach(element => {
      element.setAttribute('aria-label', language === 'en' ? element.dataset.labelEn : element.dataset.labelZh);
    });
    buttons.forEach(button => button.setAttribute('aria-pressed', String(button.dataset.language === language)));
    description.content = language === 'en'
      ? 'Computer Programming I at Sun Yat-sen University: lecture slides for Fall 2025.'
      : chineseDescription;
    try { localStorage.setItem(storageKey, language); } catch { /* Reading the page also works without browser storage. */ }
    if (updateUrl) {
      const url = new URL(location.href);
      url.searchParams.set('lang', language);
      try { history.replaceState(null, '', url); } catch { /* Some browsers restrict history for local files. */ }
    }
  }

  const requested = new URLSearchParams(location.search).get('lang');
  let saved;
  try { saved = localStorage.getItem(storageKey); } catch { /* Default to Chinese when storage is unavailable. */ }
  const language = [requested, saved].find(value => value === 'zh' || value === 'en') || 'zh';
  setLanguage(language);
  buttons.forEach(button => button.addEventListener('click', () => setLanguage(button.dataset.language, true)));
  document.querySelector('.language-switch').hidden = false;
})();
