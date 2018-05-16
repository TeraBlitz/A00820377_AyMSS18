import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { AdminService } from '../../../services/admin.service';
import { MatSnackBar } from '@angular/material';
import 'rxjs/add/operator/catch';

@Component({
  selector: 'app-admin-edit',
  templateUrl: './admin-edit.component.html',
  styleUrls: ['./admin-edit.component.scss']
})
export class AdminEditComponent implements OnInit {
  public id: any;
  public admin: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private adminService: AdminService,
    private snackBar: MatSnackBar
  ) {
    this.admin = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    if (this.id) {
      this.adminService.getAdmin(this.id).subscribe(response => {
        this.admin = response;
      });
    }
  }

  createAdmin() {
    this.adminService
      .createAdmin(this.admin)
      .catch((error, caught) => {
        this.snackBar.open(
          'El usuario no pudo ser agregado. Verificar los datos.',
          null,
          {
            duration: 2000
          }
        );
        return caught;
      })
      .subscribe(response => {
        this.router.navigateByUrl('/admin/admin/list');
      });
  }

  updateAdmin() {
    this.adminService.updateAdmin(this.admin).subscribe(() => {
      this.router.navigateByUrl('/admin/admin/list');
    });
  }
}
