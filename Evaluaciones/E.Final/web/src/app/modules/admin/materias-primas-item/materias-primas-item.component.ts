import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { MateriasPrimasService } from '../../../services/materias-primas.service';

@Component({
  selector: 'app-materias-primas-item',
  templateUrl: './materias-primas-item.component.html',
  styleUrls: ['./materias-primas-item.component.scss']
})
export class MateriasPrimasItemComponent implements OnInit {
  public id: string;
  public mp: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private mpService: MateriasPrimasService
  ) {
    this.mp = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    this.mpService.getMp(this.id).subscribe((response: any) => {
      this.mp = response.item;
    });
  }

  deleteMp() {
    this.mpService.deleteMp(this.id).subscribe(() => {
      this.router.navigateByUrl('/admin/materias-primas/list');
    });
  }
}
