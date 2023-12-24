function addBook() {
    const bookNumber = document.getElementById('bookNumber').value;
    const bookName = document.getElementById('bookName').value;
    const authorName = document.getElementById('authorName').value;
    const copies = parseInt(document.getElementById('copies').value);

    // Call C++ backend to add a book
    Module.addBook(bookNumber, bookName, authorName, copies);

    // Display the updated book list
    displayBooks();
}

function displayBooks() {
    // Call C++ backend to display books
    Module.displayBooks();
}
