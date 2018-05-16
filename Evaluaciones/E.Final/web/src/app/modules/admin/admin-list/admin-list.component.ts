import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { AdminService } from '../../../services/admin.service';

@Component({
  selector: 'app-admin-list',
  templateUrl: './admin-list.component.html',
  styleUrls: ['./admin-list.component.scss']
})
export class AdminListComponent implements OnInit {
  public admins: any;

  constructor(
    private adminService: AdminService,
    private route: ActivatedRoute
  ) {
    this.admins = [];
  }

  ngOnInit() {
    this.adminService.getAdmins().subscribe((response: any) => {
      this.admins = response.items;
    });
  }
}
