import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { AdminService } from '../../../services/admin.service';

@Component({
  selector: 'app-admin-item',
  templateUrl: './admin-item.component.html',
  styleUrls: ['./admin-item.component.scss']
})
export class AdminItemComponent implements OnInit {
  public id: string;
  public admin: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private adminService: AdminService
  ) {
    this.admin = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    this.adminService.getAdmin(this.id).subscribe(response => {
      this.admin = response;
    });
  }

  deleteAdmin() {
    this.adminService.deleteAdmin(this.id).subscribe(() => {
      this.router.navigateByUrl('/admin/admin/list');
    });
  }
}
