$('document').ready(() => {
  $.ajax({
    type: 'GET',
    url: 'https://fourtonfish.com/hellosalut/?lang=fr',
    success: (data) => {
      $('DIV#hello').text(data.hello);
    }
  });
});
