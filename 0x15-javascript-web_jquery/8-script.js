const movieList = $('UL#list_movies');
$.ajax({
  type: 'GET',
  url: 'https://swapi-api.hbtn.io/api/films/?format=json',
  success: function(data) {
    $.each(data.results, (i, dat) => {
      movieList.append(`<li>${dat.title}</li>`);
    });
  }
});
