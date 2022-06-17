$(document).ready(function() {
    // apply the page view hierarchy if it exists
    var page_view = $("#page-treeView");
    if (page_view.length) {
        page_view.treeview({
            data: getPageHierarchyTree(),
            enableLinks: true
        });
    }
    // apply the class view hierarchy if it exists
    var class_view = $("#class-treeView");
    if (class_view.length) {
        class_view.treeview({
            data: getClassViewTree(),
            enableLinks: true
        });
    }
    // apply the directory view hierarchy if it exists
    var dir_view = $("#directory-treeView");
    if (dir_view.length) {
        dir_view.treeview({
            data: getDirectoryViewTree(),
            enableLinks: true
        });
    }
});
